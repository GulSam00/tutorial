import axios from "axios";
import Link from "next/link";

export default function Books({ data }: any) {
  return (
    <>
      {data?.map(({ id, title, description }: any) => (
        <Link href={`/books/${id}`} key={id}>
          <div
            style={{
              padding: "10px",
              cursor: "pointer",
              borderBottom: "1px solid black",
            }}
          >
            <span style={{ marginRight: "10px" }}>{title}</span>
            <span>{description}</span>
          </div>
        </Link>
      ))}
    </>
  );
}

export async function getStaticProps() {
  try {
    const { data } = await axios.get("http://localhost:4000/books");
    return {
      props: { data },
      revalidate: 6000,
    };
  } catch (err) {
    return {
      notFound: true,
    };
  }
}
