import React from "react";
import { render } from "@testing-library/react";
import Hello from "./Hello";

describe("<Hello />", () => {
  it("matches snapshot", () => {
    const utils = render(<Hello first="K" name="Kim" />);
    expect(utils.container).toMatchSnapshot();
  });
  it("shows the props correctly", () => {
    const utils = render(<Hello first="K" name="Kim" />);
    utils.getByText("K"); // velopert 라는 텍스트를 가진 엘리먼트가 있는지 확인
    utils.getByText("Kim"); // (김민준) 이라는 텍스트를 가진 엘리먼트가 있는지 확인
  });
});
