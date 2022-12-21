import { apiClient, API_KEY } from "./apiType";

const Movie = {
  getMovie: async () => {
    const url = `/movie/popular?api_key=${API_KEY}`;
    const res = await apiClient.get(url);
    console.log(res);
    return res;
  },
};

export default Movie;
