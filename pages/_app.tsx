import "../styles/temp.css";
import type { AppProps } from "next/app";
import Layout from "../components/Layout";

export default function App({ Component, pageProps }: AppProps) {
  return (
    <>
      {/* Component 실제 렌더링 되는 컴포넌트. 모든 페이지, url에 적용해야 할 컴포넌트가 있다면 여기에서 적용된다. */}
      <Layout>
        <Component {...pageProps} />
      </Layout>

      <style jsx global>
        {`
          div {
            color: lightblue;
            font-size: 60px;
          }
        `}
      </style>
    </>
  );
}
