import Link from "next/link";
import styled from "styled-components";

import { useEffect, useState } from "react";
import { useRouter } from "next/router";
import Movie from "../api/Movie";

import CustomHead from "./../components/CustomHead";

const API_KEY = "479db48b922fd08fed6098721156cafb";

const Home = () => {
  const [state, setState] = useState(0);

  const [data, setData] = useState<any>([]);
  const router = useRouter();

  const getAPI = async () => {
    const test = await Movie.getMovie();
    console.log("test", test);

    const result = await (
      await fetch(
        `https://api.themoviedb.org/3/movie/popular?api_key=${API_KEY}&language=ko-KR`
      )
    ).json();
    console.log("응답 : ", result.results);
    setData(result.results);
  };
  useEffect(() => {
    getAPI();
  }, []);

  console.log("router", router);

  return (
    <Temp>
      <CustomHead title="main" />
      <div>
        <Link legacyBehavior href="/page1">
          <a className="test">page1</a>
        </Link>
        <Link href="/page2">page2</Link>
        <Link href="/page3">page3</Link>
      </div>
      <img src="/vercel.svg" />
      <h1>data = {state}</h1>
      <button onClick={() => setState((prev) => prev + 1)}>클릭!</button>
      {data.map((item: any, i: number) => (
        <div key={item.id}>{item.title}</div>
      ))}
    </Temp>
  );
};

export default Home;

const Temp = styled.div`
  .test {
    color: red;
    font-size: 20px;
  }
`;
