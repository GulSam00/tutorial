import axios from "axios";

export default function SpecificBook({
  data: { id, title, description },
}: any) {
  return (
    <>
      <div key={id}>
        <span style={{ marginRight: "10px" }}>{title}</span>
        <span>{description}</span>
      </div>
    </>
  );
}

export const getStaticPaths = async () => {
  const { data } = await axios.get("http://localhost:4000/books");
  const paths = data.map(({ id }: any) => ({ params: { id: String(id) } }));
  return { paths, fallback: "blocking" };
};

export const getStaticProps = async (context: any) => {
  try {
    const { id } = context.params;
    const { data } = await axios.get(`http://localhost:4000/books/${id}`);
    return {
      props: { data },
      revalidate: 5,
    };
  } catch (err) {
    return {
      notFound: true,
    };
  }
};
