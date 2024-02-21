import Link from "next/link";

const Page = ({ data }: any) => {
  console.log("data : ", data);
  return (
    <div>
      <Link href={"/"}>
        <h1>Back To Main</h1>
      </Link>
      {data.results.map((planet: any) => {
        return <div>{planet.name}</div>;
      })}
    </div>
  );
};

export default Page;

export async function getStaticProps() {
  const url = "https://swapi.dev/api/planets";
  // Fetch data from external API
  const res = await fetch(url);
  const data = await res.json();

  return { props: { data } };
}
