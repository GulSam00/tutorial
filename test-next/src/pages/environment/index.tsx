const Page = ({ db }: any) => {
  return (
    <>
      <h1>Server Side</h1>
      <li>db: {db.host}</li>
      <li>username: {db.username}</li>
      <li>password: {db.password}</li>
      <li>password: {db.password}</li>
      <li> {db.testInclude}</li>
      <li> {db.testExpect}</li>
      <h1>Client Side</h1>
      <li>TEST: {process.env.NEXT_PUBLIC_TEST}</li>
    </>
  );
};

export default Page;

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
