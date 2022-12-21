import { useQuery } from "react-query";
import Movie from "../api/Movie";

export const GetMovieHook = () => {
  const { status, data, error } = useQuery(
    "movie",
    async () => Movie.getMovie(),
    {
      refetchOnWindowFocus: false,
      staleTime: 1000 * 5,
      cacheTime: 1000 * 30,
      retry: 0,
    }
  );

  return { status, data, error };
};
