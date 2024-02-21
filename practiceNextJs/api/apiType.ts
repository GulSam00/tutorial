import axios from "axios";

// export function url() {
//   return `https://api.themoviedb.org/3`;
//      }

export const API_KEY = "479db48b922fd08fed6098721156cafb";

export const apiClient = axios.create({
  //   headers: {
  //     cache: "no-cache",
  //     referrer: "no-referrer",
  //     "Content-Type": "application/json",
  //     accept: "application/json",
  //   withCredentials: true,
  //   },
  baseURL: "https://api.themoviedb.org/3",
  timeout: 1000 * 60 * 3, // 3분
});
