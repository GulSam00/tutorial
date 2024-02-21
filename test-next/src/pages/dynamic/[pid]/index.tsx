import Link from "next/link";
import { useRouter } from "next/router";

const Page = () => {
  const router = useRouter();
  const { pid } = router.query;
  console.log(pid);
  return (
    <div>
      {pid !== undefined && (
        <>
          <h1>num : {pid}</h1>
          <h4>
            <Link href={`${pid}/1`}>1</Link>
          </h4>
          <h4>
            <Link href={`${pid}/2`}>2</Link>
          </h4>

          <h4>
            <Link href={`${pid}/3`}>3</Link>
          </h4>
        </>
      )}
      <h3>
        <Link href={"/"}>Home</Link>
      </h3>

      <h3>
        <Link href={"one"}>one</Link>
      </h3>
      <h3>
        <Link href={"two"}>two</Link>
      </h3>
      <h3>
        <Link href={"three"}>three</Link>
      </h3>
    </div>
  );
};

export default Page;
