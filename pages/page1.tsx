import Link from "next/link";
import CustomHead from "../components/CustomHead";
import style from "./page1.module.css";

const Home = () => {
  return (
    <>
      <CustomHead title="1" />

      <div className={style.test}>
        <Link href="/">main</Link>
        <Link href="/page1">page1</Link>
        <Link href="/page2">page2</Link>
        <Link href="/page3">page3</Link>
      </div>
      <h1 className="test">page 1</h1>
    </>
  );
};

export default Home;
