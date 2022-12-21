import Head from "next/head";

type Props = {
  title: string;
};

const CustomHead = ({ title }: Props) => {
  return (
    <>
      <Head>
        <title>{title} | My Page</title>
      </Head>
    </>
  );
};

export default CustomHead;
