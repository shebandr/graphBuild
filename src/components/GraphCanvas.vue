<template>
  <div>
    <div v-show="showButton" @click="createGraph" class="buttonBuild">Построить таблицу</div>
    <canvas id="test" height="900" width="1150">Текст показывается, если элемент не поддерживается</canvas>
  </div>
</template>

<script>
export default {
  props: {
    message: {
      type: String,
      required: true
    }
  },

  data() {
    return {
      showButton: true
    }
  },
  methods: {
    createGraph() {
      this.showButton = false
      var arrays = this.message.split("\n")
      var arraysSplitted = [[], [], [], []]
      for (var w = 0; w < 3; w++) {
        arraysSplitted[w] = arrays[w].split(" ")

      }
      for(w=10;w<=1000;w+=10){
        arraysSplitted[3][(w/10)-1]=w*Math.log2(w)
      }
      console.log(arrays[0].split(" "))
      var canvas = document.getElementById("test");
      var ctx = canvas.getContext('2d');
      /* Рисует контур прямоугольника на всю ширину и высоту canvas */
      ctx.beginPath();
      ctx.strokeRect(0, 0, canvas.width, canvas.height);
      ctx.strokeRect(0, 0, canvas.width, canvas.height);
      ctx.moveTo(50, 850)
      ctx.lineTo(50, 50)
      ctx.moveTo(50, 850)
      ctx.lineTo(1100, 850)
      ctx.moveTo(30, 70)
      ctx.lineTo(50, 50)
      ctx.moveTo(70, 70)
      ctx.lineTo(50, 50)
      ctx.moveTo(1080, 830)
      ctx.lineTo(1100, 850)
      ctx.moveTo(1080, 870)
      ctx.lineTo(1100, 850)
      for (var q = 150; q < 1100; q += 100) {
        ctx.moveTo(q, 840)
        ctx.lineTo(q, 860)
      }
      for (q = 100; q < 850; q += 50) {
        ctx.moveTo(40, q)
        ctx.lineTo(60, q)
      }
      var z = 0
      for (q = 850; q >= 100; q -= 50) {
        ctx.fillText(z, 15, q)
        z += 2000
      }
      z = 0
      for (q = 50; q <= 1150; q += 100) {
        ctx.fillText(z, q, 880)
        z += 100
      }
      z = 850
      w = 1

      ctx.stroke(); // обводим фигуры
      ctx.beginPath()
      ctx.strokeStyle="gray"
      for(q = 900;q>50;q-=50){
        ctx.moveTo(50, q)
        ctx.lineTo(1100, q)
      }
      ctx.stroke();
      ctx.beginPath()
      ctx.strokeStyle="gray"
      for(q = 50;q<=1100;q+=100){
        ctx.moveTo(q, 850)
        ctx.lineTo(q, 50)
      }
      ctx.stroke();

      ctx.beginPath()
      ctx.strokeStyle = "black"
      ctx.moveTo(50, 850)
      z=850
      w=1
       delitel = 100
      for (q = 50; q <= 1150; q += 10) {
        ctx.lineTo(q + 10, z - (arraysSplitted[3][w] / delitel))
        z -= arraysSplitted[0][w] / 3000
        w++
      }
      ctx.strokeText( "nlog2n - черный", 800, 50)
      ctx.stroke(); // обводим фигуры
      ctx.beginPath()
      ctx.strokeStyle = "red"
      ctx.moveTo(50, 850)
      z=850
      w=1
      var delitel = 100
      for (q = 50; q <= 1150; q += 10) {
        ctx.lineTo(q + 10, z - (arraysSplitted[0][w] / delitel))
        z -= arraysSplitted[0][w] / 3000
        w++
      }
      ctx.strokeText( "Mergesort - красный", 200, 50)
      ctx.stroke(); // обводим фигуры
      ctx.beginPath()
      z = 850
      w = 1
      ctx.strokeStyle = "blue"
      ctx.moveTo(50, 850)
      for (q = 50; q <= 1150; q += 10) {
        ctx.lineTo(q + 10, z - (arraysSplitted[0][w] / delitel))
        z -= arraysSplitted[1][w] / 3000
        w++
      }
      ctx.strokeText( "Quicksort - синий", 400, 50)
      ctx.stroke(); // обводим фигуры
      ctx.beginPath()
      z = 850
      w = 1
      ctx.strokeStyle = 'green'
      ctx.moveTo(50, 850)
      for (q = 50; q <= 1150; q += 10) {

        ctx.lineTo(q + 10, z - (arraysSplitted[0][w] / delitel))
        z -= arraysSplitted[2][w] / 3000
        w++
      }
      ctx.strokeText( "Heapsort - красный", 600, 50)
      ctx.stroke(); // обводим фигуры

    }

  }
}
</script>

<style>
canvas {
  display: block;
  margin: auto;
}
.buttonBuild {
  display: block;
  width: 200px;
  height: 30px;
  border: 3px gray solid;
  border-radius: 15px;
  text-align: center;
  line-height: 200%;
  cursor: pointer;
  margin: auto;
}
</style>