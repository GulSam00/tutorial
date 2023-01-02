import { useQuery } from "react-query";
import Todos from "../api/Todos";

// export const PostTodoHook = (title: string) => {
//   const { status, data, error } = useMutation(async () =>
//     Todos.postTodo(title)
//   );
//   return { status, data, error };
// };

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

// export const PutTodoHook = (id: number, title: string, isDone: boolean) => {
//   const { status, data, error } = useQuery(
//     "todos",
//     async () => Todos.putTodo(id, title, isDone),
//     {
//       refetchOnWindowFocus: false,
//       staleTime: 1000 * 5,
//       cacheTime: 1000 * 30,
//       retry: 0,
//     }
//   );
//   return { status, data, error };
// };

// export const DeleteTodoHook = (id: number) => {
//   const { status, data, error } = useQuery(
//     "todos",
//     async () => Todos.deleteTodo(id),
//     {
//       refetchOnWindowFocus: false,
//       staleTime: 1000 * 5,
//       cacheTime: 1000 * 30,
//       retry: 0,
//     }
//   );
//   return { status, data, error };
// };
