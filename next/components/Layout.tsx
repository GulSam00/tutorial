const Layout = ({ children }: any) => {
  return (
    <>
      <div>위</div>
      <div>{children}</div>
      <div>아래</div>
    </>
  );
};

export default Layout;
