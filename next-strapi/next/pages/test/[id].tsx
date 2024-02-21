import { useState } from "react";
import { GetStaticProps, GetServerSideProps } from "next";

const Test = ({ todos }: any) => {
  const [num, setNum] = useState(0);
  console.log("Test");
  console.log("todos : ", todos);
  return (
    <>
      <h1>Test</h1>
      <h2>{num}</h2>
      <button onClick={() => setNum(num + 1)}>버튼</button>
    </>
  );
};

export default Test;

export const getStaticPaths = async () => {
  console.log("getStaticPaths");
  return {
    paths: [
      { params: { id: "1" } },
      { params: { id: "2" } },
      { params: { id: "4" } },
    ],
    // { parmas: {} }[] 형태로 paths 리턴해야 함
    // 빌드 시에 해당 페이지들을 static으로 생성
    fallback: false,
    // fallback을 리턴해야 함
  };
};

export const getStaticProps: GetStaticProps = async (path) => {
  console.log("getStaticProps");
  console.log("path : ", path);
  const res = [{ id: 1 }, { id: 2 }, { id: 4 }];

  return {
    props: {
      res,
    },
  };
};
