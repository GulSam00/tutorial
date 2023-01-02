import { useState } from "react";
import styled from "styled-components";
import Todos from "../api/Todos";
import { useMutation, useQueryClient } from "react-query";

import Checkbox from "@mui/material/Checkbox";
import FormGroup from "@mui/material/FormGroup";
import Button from "@mui/material/Button";
import TextField from "@mui/material/TextField";

import { GetTodosHook } from "../hook/todos";
import CustomHead from "./../components/CustomHead";

type Todo = {
  id: number;
  attributes: {
    createdAt: string;
    publishedAt: string;
    updatedAt: string;
    isDone: boolean;
    title: string;
  };
};

const Home = () => {
  const [newTodo, setNewTodo] = useState<string>("");

  const queryClient = useQueryClient();

  const { mutate: mutateDelete } = useMutation(Todos.deleteTodo, {
    // 옵션
    onError: (err) => {
      alert("글을 삭제하지 못했습니다.");
    },
    onSuccess: () => {
      console.log("글이 삭제되었습니다.");
      queryClient.invalidateQueries("todos");
    },
    onSettled: () => {
      console.log("삭제 요청이 실행되었습니다.");
    },
  });

  const { mutate: mutatePost } = useMutation(Todos.postTodo, {
    // 옵션
    onError: (err) => {
      alert("글을 생성하지 못했습니다.");
    },
    onSuccess: () => {
      console.log("글이 생성되었습니다.");
      queryClient.invalidateQueries("todos");
    },
    onSettled: () => {
      console.log("생성 요청이 실행되었습니다.");
    },
  });

  const { mutate: mutatePut } = useMutation(
    (args: any) => Todos.putTodo(args[0], args[1]),
    {
      // 옵션
      onError: (err) => {
        alert("글을 수정하지 못했습니다.");
      },
      onSuccess: () => {
        console.log("글이 수정되었습니다.");
        queryClient.invalidateQueries("todos");
      },
      onSettled: () => {
        console.log("수정 요청이 실행되었습니다.");
      },
    }
  );

  const { data, status, error } = GetTodosHook();

  const todos = data?.data.data;
  console.log(data, status, error);
  console.log(todos);

  const handlePost = async () => {
    if (newTodo === "") return;
    setNewTodo("");
    mutatePost(newTodo);
  };

  return (
    <>
      <Container>
        <CustomHead title="main" />
        <h1>메인 페이지</h1>

        <TextField
          id="outlined-basic"
          label="할일"
          variant="outlined"
          value={newTodo}
          onChange={(e) => setNewTodo(e.target.value)}
        />

        <Button variant="text" onClick={handlePost}>
          submit
        </Button>

        <FormGroup>
          {todos &&
            todos.map((todo: Todo) => (
              <div key={todo.id}>
                <Checkbox
                  checked={todo.attributes.isDone}
                  onChange={() => mutatePut([todo.id, !todo.attributes.isDone])}
                />
                <text>{todo.attributes.title}</text>

                <Button variant="text" onClick={() => mutateDelete(todo.id)}>
                  delete
                </Button>
              </div>
            ))}
        </FormGroup>
      </Container>
    </>
  );
};

export default Home;

const Container = styled.div``;
