main = do
  count::Int <- read <$> getLine
  putStrLn $ "count = " ++ show count
