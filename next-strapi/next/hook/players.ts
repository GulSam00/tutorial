import { useQuery, useMutation } from "react-query";

import Players from "../api/Players";

export const GetPlayersHook = () => {
  const { status, data, error } = useQuery(
    "players",
    async () => Players.getPlayers(),
    {
      refetchOnWindowFocus: false,
      cacheTime: 1000 * 5,
      retry: 0,
    }
  );
  return { status, data, error };
};

export const DeletePlayersHook = (queryClient: any) => {
  const { mutate } = useMutation(Players.deletePlayers, {
    // 옵션
    onError: (err) => {
      alert("사용자를 삭제하지 못했습니다.");
    },
    onSuccess: () => {
      console.log("사용자가 삭제되었습니다.");
      queryClient.invalidateQueries("players");
    },
    onSettled: () => {
      console.log("삭제 요청이 실행되었습니다.");
    },
  });

  return mutate;
};

export const PostPlayersHook = (queryClient: any) => {
  const { mutate } = useMutation(
    (args: string[]) => Players.postPlayers(args[0], args[1], args[2]),
    {
      // 옵션
      onError: (err) => {
        alert("사용자를 생성하지 못했습니다.");
      },
      onSuccess: () => {
        console.log("사용자가 생성되었습니다.");
        queryClient.invalidateQueries("players");
      },
      onSettled: () => {
        console.log("생성 요청이 실행되었습니다.");
      },
    }
  );

  return mutate;
};

export const PutPlayersHook = (queryClient: any) => {
  const { mutate } = useMutation(
    (args: any) => Players.putPlayers(args[0], args[1]),
    {
      // 옵션
      onError: (err) => {
        alert("사용자를 수정하지 못했습니다.");
      },
      onSuccess: () => {
        console.log("사용자가 수정되었습니다.");
        queryClient.invalidateQueries("players");
      },
      onSettled: () => {
        console.log("수정 요청이 실행되었습니다.");
      },
    }
  );
  return mutate;
};
