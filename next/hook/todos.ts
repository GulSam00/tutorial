import { useQuery } from "react-query";
import Todos from "../api/Todos";

export const GetTodosHook = () => {
  const { status, data, error } = useQuery(
    "todos",
    async () => Todos.getTodos(),
    {
      refetchOnWindowFocus: false,
      staleTime: 1000 * 5,
      cacheTime: 1000 * 30,
      retry: 0,
    }
  );

  return { status, data, error };
};
