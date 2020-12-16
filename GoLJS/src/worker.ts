import { parentPort, workerData } from 'worker_threads';
let tmp: number[]=[];

// function surroundings(data: number[][], i:number, j:number){
// 	let counter=0;
// 	for (let k=i-1;k<i+2; ++k){
// 		for (let l=j-1; l<j+2; ++l){
// 			if (k >= 0 &&
// 				l >= 0 &&
// 				k < data.length &&
// 				l < data[0].length &&
// 				(!(k == i && l == j))){
// 				if(data[k][l]==1){
// 					++counter;
// 				}
// 			}
// 		}
// 	}
// 	return counter;
//
// }


// console.log(workerData.data[workerData.id].length);

for (let j=0; j<workerData.data[0].length; ++j){
	let counter=0;
	for (let k=workerData.id-1;k<workerData.id+2; ++k){
		for (let l=j-1; l<j+2; ++l){
			if (k >= 0 &&
				l >= 0 &&
				k < workerData.data.length &&
				l < workerData.data[0].length &&
				(!(k == workerData.id && l == j))){
				if(workerData.data[k][l]==1){
					++counter;
				}
			}
		}
	}
	// console.log(counter);
	if (workerData.data[workerData.id][j] && counter<2 ){
		tmp.push(0);
	}
	else if (workerData.data[workerData.id][j] && (counter == 2 || counter == 3 )){
		tmp.push(1);
	}
	else if (workerData.data[workerData.id][j] && counter >3){
		tmp.push(0);
	}
	else if (!workerData.data[workerData.id][j] && counter==3 ){
		tmp.push(1);
	}
	else{
		tmp.push(0)
	}

}


// console.log([workerData.id, tmp]);
parentPort?.postMessage(tmp);

// parentPort?.postMessage(`Hi! I'm worker number ${workerData.id}, ${workerData.data}`);