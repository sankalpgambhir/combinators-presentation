module Main where

double :: [a] -> [a]
double [] = []
double (x : xs) = x : x : double xs

main :: IO ()
main =
    putStrLn $ show l
    where l = length doobl
          doobl = double src
          src = [1..1e7]
