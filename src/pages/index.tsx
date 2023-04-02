import { Inter } from "next/font/google";
import Link from "next/link";

const inter = Inter({ subsets: ["latin"] });

export default function Home() {
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
    </div>
  );
}
