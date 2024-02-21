import { Inter } from "next/font/google";
import Link from "next/link";

const inter = Inter({ subsets: ["latin"] });

export default function Home() {
  return (
    <div>
      test
      <div>
        <h1>1주차</h1>
        <h3>
          <Link href="/about">About</Link>
        </h3>
        <h3>
          <Link href="/getStaticProps">getStaticProps</Link>
        </h3>
        <h3>
          <Link href="/getStaticPaths">getStaticPaths</Link>
        </h3>
        <h3>
          <Link href="/getServerSideProps">getServerSideProps</Link>
        </h3>
        <h1>2주차</h1>

        <h3>
          <Link href="/environment">Environment</Link>
        </h3>

        <h3>
          <Link href="/dynamic">Dynamic Route</Link>
        </h3>
      </div>
      <Link
        href={{
          pathname: "/inside/[slug]",
          query: { slug: "test" },
        }}
      >
        test
      </Link>
      <Link
        href={{
          pathname: "/inside/query?",
          query: { slug: "test" },
        }}
      >
        query
      </Link>
    </div>
  );
}
