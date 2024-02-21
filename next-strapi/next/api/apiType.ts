import axios from "axios";

export const apiClient = axios.create({
  //   headers: {
  //     cache: "no-cache",
  //     referrer: "no-referrer",
  //     "Content-Type": "application/json",
  //     accept: "application/json",
  //   withCredentials: true,
  //   },
  baseURL: "http://localhost:1337/api/",
  timeout: 1000 * 60 * 3, // 3분
});
