import Link from "next/link";

const Page = ({ data }: any) => {
  console.log(data);
  return (
    <div>
      <Link href={"/getStaticPaths"}>
        <h1>Back</h1>
      </Link>
      <div>{data.name}</div>
      <li>Climate: {data.climate}</li>
      <li>Diameter: {data.diameter}</li>
      <li>Gravity: {data.gravity}</li>
      <li>Orbital Period: {data.orbital_period}</li>
    </div>
  );
};

export default Page;

export async function getStaticPaths() {
  const url = "https://swapi.dev/api/planets";
  // Fetch data from external API
  const res = await fetch(url);
  const data = await res.json();
  // name 순으로 뽑아냄
  const paths = data.results.map((planet: any, i: number) => ({
    params: { id: String(i) },
  }));

  return {
    paths,
    fallback: false, // can also be true or 'blocking'
  };
}

export async function getStaticProps({ params }: any) {
  const url = `https://swapi.dev/api/planets/${params.id}`;

  const res = await fetch(url);
  const data = await res.json();

  return {
    props: {
      data,
    },
  };
}
