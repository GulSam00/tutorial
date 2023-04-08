import { Inter } from "next/font/google";
import Link from "next/link";

const inter = Inter({ subsets: ["latin"] });

export default function Home({ db }: any) {
  return (
    <div>
      test
      <div>
        <h1>
          <Link href="/about">About</Link>
        </h1>
        <h1>
          <Link href="/getStaticProps">getStaticProps</Link>
        </h1>
        <h1>
          <Link href="/getStaticPaths">getStaticPaths</Link>
        </h1>
        <h1>
          <Link href="/getServerSideProps">getServerSideProps</Link>
        </h1>
      </div>
      <li>db: {db.host}</li>
      <li>username: {db.username}</li>
      <li>password: {db.password}</li>
      <li>password: {db.password}</li>
      <li> {db.testInclude}</li>
      <li> {db.testExpect}</li>
    </div>
  );
}

export async function getStaticProps() {
  const db = {
    host: process.env.DB_HOST,
    username: process.env.DB_USER,
    password: process.env.DB_PASS,
    test: process.env.TEST,
    testInclude: process.env.TEST_INCLUDE,
    testExpect: process.env.TEST_INCLUDE_EXCEPT,
  };

  return { props: { db } };
}
