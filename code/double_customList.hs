module Main where

data List a = Nil | Cons a (List a)

double :: List a -> List a
double Nil = Nil
double (Cons x xs) = Cons x (Cons x (double xs))

enum :: Int -> List Int
enum 0 = Nil
enum n = Cons n (enum (n-1))

len :: List a -> Int
len Nil = 0
len (Cons _ xs) = 1 + len xs

main :: IO ()
main =
    putStrLn $ show l
    where l = len doobl
          doobl = double src
          src = enum 10000
