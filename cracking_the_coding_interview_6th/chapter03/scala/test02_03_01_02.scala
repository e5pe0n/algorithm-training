package scala

object Main_test02_03_01_02 extends App {
  val tio = new ThreeInOne2(5)
  for (i <- 10 until 13) tio.push(tio.s1, i)
  for (i <- 20 until 23) tio.push(tio.s2, i)
  for (i <- 30 until 33) tio.push(tio.s3, i)
  println(tio)
  for (i <- 23 until 29) tio.push(tio.s2, i)
  println(tio)
  tio.push(tio.s2, 29)
}

//    [10 11 12  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt            ^              ^              ^

//    [31 32 10 11 12 20 21 22 23 24 25 26 27 28 30]
// btm        ^        ^                          ^
// pt         ^        ^                          ^

// [error] (run-main-0) scala.FullStackException: stack is full
// [error] scala.FullStackException: stack is full
