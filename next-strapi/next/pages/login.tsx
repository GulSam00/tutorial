import { useState } from "react";
import { useRouter } from "next/router";
import { useQueryClient } from "react-query";

import TextField from "@mui/material/TextField";
import OutlinedInput from "@mui/material/OutlinedInput";
import IconButton from "@mui/material/IconButton";
import InputLabel from "@mui/material/InputLabel";
import InputAdornment from "@mui/material/InputAdornment";
import FormControl from "@mui/material/FormControl";
import Visibility from "@mui/icons-material/Visibility";
import VisibilityOff from "@mui/icons-material/VisibilityOff";
import Button from "@mui/material/Button";

import { GetPlayersHook, PostPlayersHook } from "../hook/players";

const Login = () => {
  const { data: playerData } = GetPlayersHook();
  console.log("player : ", playerData?.data.data);

  const queryClient = useQueryClient();
  const mutatePost = PostPlayersHook(queryClient);

  const [isLogin, setIsLogin] = useState<boolean>(true);
  const [userName, setUserName] = useState<string>("");
  const [userId, setUserId] = useState<string>("");
  const [password, setPassword] = useState<string>("");
  const [showPassword, setShowPassword] = useState<boolean>(false);

  const router = useRouter();

  const handlePost = async () => {
    setUserName("");
    setUserId("");
    setPassword("");
    if (isLogin) {
    } else {
      mutatePost([userName, userId, password]);
      localStorage.setItem("user", userName);
      router.push("/");
    }
  };

  return (
    <>
      <h1>어서오세요</h1>
      <div>
        <h2>{isLogin ? "로그인" : "회원가입"}</h2>

        {!isLogin && (
          <TextField
            id="outlined-basic"
            label="닉네임"
            variant="outlined"
            value={userName}
            onChange={(e) => setUserName(e.target.value)}
          />
        )}
        <TextField
          id="outlined-basic"
          label="아이디"
          variant="outlined"
          value={userId}
          onChange={(e) => setUserId(e.target.value)}
        />
        <FormControl sx={{ m: 1, width: "25ch" }} variant="outlined">
          <InputLabel htmlFor="outlined-adornment-password">
            비밀번호
          </InputLabel>
          <OutlinedInput
            type={showPassword ? "text" : "password"}
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            endAdornment={
              <InputAdornment position="end">
                <IconButton
                  aria-label="toggle password visibility"
                  onClick={() => setShowPassword(!showPassword)}
                >
                  {showPassword ? <VisibilityOff /> : <Visibility />}
                </IconButton>
              </InputAdornment>
            }
          />
        </FormControl>
      </div>

      <Button variant="text" onClick={() => setIsLogin(!isLogin)}>
        {isLogin ? "회원가입 전환" : "로그인 전환"}
      </Button>
      <Button variant="text" onClick={handlePost}>
        {isLogin ? "로그인" : "회원가입"}
      </Button>
    </>
  );
};

export default Login;
