import { apiClient } from "./apiType";

const Todos = {
  getTodos: async () => {
    const url = `todos`;
    const res = await apiClient.get(url);
    console.log(res);
    return res;
  },
};

export default Todos;
