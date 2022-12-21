import Link from "next/link";

const Home = () => {
  return (
    <>
      <div>
        <nav>
          <a href="/page1">nav</a>
        </nav>
        <Link href="/">main</Link>
        <Link href="/page1">page1</Link>
        <Link href="/page2">page2</Link>
        <Link href="/page3">page3</Link>
      </div>
      <h1>page 3</h1>
    </>
  );
};

export default Home;
