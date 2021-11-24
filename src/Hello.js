import React from "react";

const Hello = ({ first, name }) => {
  return (
    <div>
      <b>{first}</b>&nbsp;
      <span>{name}</span>
    </div>
  );
};

export default Hello;
