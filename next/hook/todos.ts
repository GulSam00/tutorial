import { useQuery, useMutation } from "react-query";

import Todos from "../api/Todos";

export const GetTodosHook = () => {
  const { status, data, error } = useQuery(
    "todos",
    async () => Todos.getTodos(),
    {
      refetchOnWindowFocus: false,
      cacheTime: 1000 * 5,
      retry: 0,
    }
  );
  return { status, data, error };
};

export const DeleteTodoHook = (queryClient: any) => {
  const { mutate } = useMutation(Todos.deleteTodo, {
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

  return mutate;
};

export const PostTodoHook = (queryClient: any) => {
  const { mutate } = useMutation(Todos.postTodo, {
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

  return mutate;
};

export const PutTodoHook = (queryClient: any) => {
  const { mutate } = useMutation(
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
  return mutate;
};
