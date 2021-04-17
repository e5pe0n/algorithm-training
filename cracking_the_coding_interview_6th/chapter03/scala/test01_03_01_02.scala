package scala

object Main_test01_03_01_02 extends App {
  val tio = new ThreeInOne2(5)
  for (i <- 10 until 13) tio.push(tio.s1, i)
  for (i <- 20 until 23) tio.push(tio.s2, i)
  for (i <- 30 until 33) tio.push(tio.s3, i)
  println(tio)
  for (i <- 10 until 13) println(tio.pop(tio.s1))
  for (i <- 20 until 23) println(tio.pop(tio.s2))
  for (i <- 30 until 33) println(tio.pop(tio.s3))
  println(tio)
  for (i <- 50 until 53) tio.push(tio.s1, i)
  println(tio)
  for (i <- 50 until 53) println(tio.pop(tio.s1))
  println(tio)
  tio.pop(tio.s1)
}

//    [10 11 12  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt            ^              ^              ^

// 12
// 11
// 10
// 22
// 21
// 20
// 32
// 31
// 30
//    [10 11 12  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt   ^              ^              ^

//    [50 51 52  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt            ^     ^              ^

// 52
// 51
// 50
//    [50 51 52  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt   ^              ^              ^

// [error] (run-main-0) scala.EmptyStackException: stack is empty
// [error] scala.EmptyStackException: stack is empty
