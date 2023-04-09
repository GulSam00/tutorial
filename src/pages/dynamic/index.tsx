import Link from "next/link";

const Page = () => {
  return (
    <div>
      <h1>
        <Link href={"/"}>Home</Link>
      </h1>

      <h3>
        <Link href={"dynamic/one"}>one</Link>
      </h3>
      <h3>
        <Link href={"dynamic/two"}>two</Link>
      </h3>
      <h3>
        <Link href={"dynamic/three"}>three</Link>
      </h3>
    </div>
  );
};

export default Page;
