import { useState } from "react";

const Home = () => {
  const [state, setState] = useState(0);

  return (
    <>
      <h1>data = {state}</h1>
      <button onClick={() => setState((prev) => prev + 1)}>click</button>
    </>
  );
};

export default Home;
