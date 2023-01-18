import { useState } from "react";
import styled from "styled-components";
import { useQueryClient } from "react-query";

import Checkbox from "@mui/material/Checkbox";
import FormGroup from "@mui/material/FormGroup";
import Button from "@mui/material/Button";
import TextField from "@mui/material/TextField";

import {
  GetTodosHook,
  PostTodoHook,
  DeleteTodoHook,
  PutTodoHook,
} from "../hook/todos";
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

  const mutateDelete = DeleteTodoHook(queryClient);
  const mutatePost = PostTodoHook(queryClient);
  const mutatePut = PutTodoHook(queryClient);

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
