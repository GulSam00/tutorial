import Link from "next/link";
import styled from "styled-components";

import { useEffect, useState } from "react";
import { useRouter } from "next/router";
import { GetMovieHook } from "../hook/movie";

import CustomHead from "./../components/CustomHead";

const Home = () => {
  const [state, setState] = useState(0);
  const { data: movieData, status, error } = GetMovieHook();
  const data = movieData?.data.results;
  console.log("movieData", movieData);
  console.log("status", status);
  console.log("error", error);

  const router = useRouter();

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
      <div className="container">
        {!data && <h4>Loading...</h4>}
        {data?.map((movie) => (
          <div className="movie" key={movie.id}>
            <img src={`https://image.tmdb.org/t/p/w500/${movie.poster_path}`} />
            <h4>{movie.original_title}</h4>
          </div>
        ))}
      </div>
    </Temp>
  );
};

export default Home;

const Temp = styled.div`
  .container {
    display: grid;
    grid-template-columns: 1fr 1fr;
    padding: 20px;
    gap: 20px;
  }
  .movie img {
    max-width: 100%;
    border-radius: 12px;
    transition: transform 0.2s ease-in-out;
    box-shadow: rgba(0, 0, 0, 0.1) 0px 4px 12px;
  }
  .movie:hover img {
    transform: scale(1.05) translateY(-10px);
  }
  .movie h4 {
    font-size: 18px;
    text-align: center;
  }
`;
