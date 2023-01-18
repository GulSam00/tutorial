import { useState, useEffect } from "react";
import { useQueryClient } from "react-query";
import { useRouter } from "next/router";
import styled from "styled-components";

import Checkbox from "@mui/material/Checkbox";
import FormGroup from "@mui/material/FormGroup";
import Button from "@mui/material/Button";
import TextField from "@mui/material/TextField";

import CustomHead from "./../components/CustomHead";

import {
  GetTodosHook,
  PostTodoHook,
  DeleteTodoHook,
  PutTodoHook,
} from "../hook/todos";

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
  const queryClient = useQueryClient();
  const router = useRouter();

  const mutateDelete = DeleteTodoHook(queryClient);
  const mutatePost = PostTodoHook(queryClient);
  const mutatePut = PutTodoHook(queryClient);

  const { data: todoData } = GetTodosHook();
  const todos = todoData?.data.data;
  console.log(todos);

  const [newTodo, setNewTodo] = useState<string>("");

  const handlePost = async () => {
    if (newTodo === "") return;
    setNewTodo("");
    mutatePost(newTodo);
  };

  useEffect(() => {
    const user = localStorage.getItem("user");
    if (!user) {
      // router.push("/login");
    }
  }, []);

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
                  // onChange={() => mutatePut( {id : todo.id, isDone :!todo.attributes.isDone})}
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
