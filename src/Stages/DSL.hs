module Stages.DSL
    ( Stream
    , Expression
    , (=:)
    , clock
    , streamMap
    , isEven
    , not
    , stringConstant
    , compileProgram
    ) where

import Control.Monad.State

import Prelude hiding (not)
import qualified Types.AST as AST
import Stages.Analyze (astToStreams)
import Stages.CodeGen (streamsToC)

newtype Stream a = Stream { unStream :: AST.Stream }

newtype Expression a = Expression { unExpression :: AST.Expression }

-- TODO: make phantom type for output
(=:) :: AST.Output -> Stream a -> State AST.Program ()
(=:) output stream = do
    modify $ addStatement $ AST.Assignment output (unStream stream)
    where
        addStatement :: AST.Statement -> AST.Program -> AST.Program
        addStatement x (AST.Program xs) = AST.Program $ xs ++ [x]

clock :: Stream Int
clock = Stream $ AST.Builtin "clock"

streamMap :: (Expression a -> Expression b) -> Stream a -> Stream b
streamMap fn stream = Stream $ AST.Custom [unStream stream] expression
    where
        expression = unExpression $ fn $ Expression $ AST.Input 0

not :: Expression Bool -> Expression Bool
not = Expression . AST.Not . unExpression

isEven :: Expression Int -> Expression Bool
isEven = Expression . AST.Even . unExpression

stringConstant :: String -> Expression String
stringConstant = Expression . AST.StringConstant

compileProgram :: State AST.Program () -> IO ()
compileProgram state = do
    let ast = execState state (AST.Program [])
    let streams = astToStreams ast
    let cCode = streamsToC streams
    writeFile "main.c" cCode
