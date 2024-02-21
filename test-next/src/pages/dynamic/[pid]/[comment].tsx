import { useRouter } from "next/router";
import Link from "next/link";

const Page = () => {
  const router = useRouter();
  const { comment } = router.query;

  return (
    <>
      <div>{comment !== undefined && <h1>comment : {comment}</h1>}</div>

      <div>
        {" "}
        <Link href={`/dynamic`}>turn back dynamic</Link>
      </div>
    </>
  );
};

export default Page;
