import { apiClient } from "./apiType";

const Todos = {
  postTodo: async (title: string) => {
    const url = `todos`;
    const data = { title, isDone: false };
    const res = await apiClient.post(url, { data });
    console.log(res);
    return res;
  },

  getTodos: async () => {
    const url = `todos`;
    const res = await apiClient.get(url);
    console.log(res);
    return res;
  },

  putTodo: async (id: number, isDone: boolean) => {
    const url = `todos/${id}`;

    const data = { isDone };

    const res = await apiClient.put(url, { data });
    console.log(res);
    return res;
  },

  deleteTodo: async (id: number) => {
    const url = `todos/${id}`;
    const res = await apiClient.delete(url);
    console.log(res);
    return res;
  },
};

export default Todos;
