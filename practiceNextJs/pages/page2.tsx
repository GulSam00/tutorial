import Link from "next/link";
import CustomHead from "../components/CustomHead";

const Home = () => {
  const teal = "teal";

  return (
    <>
      <CustomHead title="2" />
      <div>
        <Link href="/">main</Link>
        <Link href="/page1">page1</Link>
        <Link href="/page2">page2</Link>
        <Link href="/page3">page3</Link>
      </div>
      <h1>page 2</h1>
      <style jsx>
        {`
          div {
            color: ${teal};
            font-size: 40px;
          }
        `}
      </style>
    </>
  );
};

export default Home;
