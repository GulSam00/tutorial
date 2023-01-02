import { useQuery } from "react-query";
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
