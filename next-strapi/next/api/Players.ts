import { apiClient } from "./apiType";

const Players = {
  postPlayers: async (username: string, userId: string, password: string) => {
    const url = `players`;
    const data = { username, userId, password };
    const res = await apiClient.post(url, { data });
    console.log(res);
    return res;
  },

  getPlayers: async () => {
    const url = `players`;
    const res = await apiClient.get(url);
    console.log(res);
    return res;
  },

  putPlayers: async (id: number, isDone: boolean) => {
    const url = `players/${id}`;

    const data = { isDone };

    const res = await apiClient.put(url, { data });
    console.log(res);
    return res;
  },

  deletePlayers: async (id: number) => {
    const url = `players/${id}`;
    const res = await apiClient.delete(url);
    console.log(res);
    return res;
  },
};

export default Players;
