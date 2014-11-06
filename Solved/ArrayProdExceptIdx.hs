{-# LANGUAGE ScopedTypeVariables, ParallelListComp #-}

import Control.Applicative

{- You have an array of integers, and for each index you want to find the
 - product of every integer except the integer at that index. Write a function
 - get_products_of_all_ints_except_at_index() that takes an array of integers and
 - returns an array of the products.
 -
 - For example, given:
 -  [1, 7, 3, 4]
 - your function would return:
 -  [84, 12, 28, 21]
 - by calculating:
 -  [7-3-4, 1-3-4, 1-7-4, 1-7-3]
 - Do not use division in your solution.
 -}

main = do
  count::Int <- read <$> getLine
  arr :: [Int] <- (map read) . words <$> getLine
  print arr
  let (_,revf2b) = foldl (\(prod, res) e -> (e*prod, prod:res)) (1,[]) arr
  let (_,b2f) = foldr (\e (prod, res)-> (e*prod, prod:res)) (1,[]) arr
  print $ [x*y | x <- reverse revf2b | y <- b2f]
