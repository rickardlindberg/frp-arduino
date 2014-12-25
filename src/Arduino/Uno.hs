module Arduino.Uno
    ( module Arduino.Language
    , module Arduino.Library
    , module Arduino.Uno
    ) where

import Arduino.Language
import Arduino.Library
import qualified Arduino.Internal.DAG as DAG
import qualified Arduino.Internal.DSL as DSL

-- For mappings, see http://arduino.cc/en/Hacking/PinMapping168

pin13 :: Stream Bool -> Stream Bool
pin13 = DSL.output $ DAG.OutputPin $ DAG.Pin "pin13" "PORTB" "PINB" "DDRB" "0x20U"

pin12 :: Stream Bool -> Stream Bool
pin12 = DSL.output $ DAG.OutputPin $ DAG.Pin "pin12" "PORTB" "PINB" "DDRB" "0x10U"

pin12in :: Stream Bool
pin12in = DSL.input $ DAG.InputPin $ DAG.Pin "pin12" "PORTB" "PINB" "DDRB" "0x10U"

uart :: Stream String -> Stream String
uart = DSL.output $ DAG.OutputPin $ DAG.UART