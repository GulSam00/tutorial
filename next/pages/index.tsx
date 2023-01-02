import { useEffect, useState } from "react";
import Link from "next/link";
import styled from "styled-components";

import Checkbox from "@mui/material/Checkbox";
import FormGroup from "@mui/material/FormGroup";
import FormControlLabel from "@mui/material/FormControlLabel";

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
  const { data, status, error } = GetTodosHook();
  const todos = data?.data.data;
  console.log(data, status, error);
  console.log(todos);

  const handleChange = (id: number) => {
    console.log(id);
  };

  return (
    <>
      <Container>
        <CustomHead title="main" />
        <h1>메인 페이지</h1>
        <FormGroup>
          {todos &&
            todos.map((todo: Todo) => (
              <FormControlLabel
                key={todo.id}
                control={
                  <Checkbox
                    checked={todo.attributes.isDone}
                    onChange={() => handleChange(todo.id)}
                  />
                }
                label={todo.attributes.title}
              />
            ))}
        </FormGroup>
      </Container>
    </>
  );
};

export default Home;

const Container = styled.div``;
