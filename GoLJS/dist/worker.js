"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const worker_threads_1 = require("worker_threads");
let tmp = [];
for (let j = 0; j < worker_threads_1.workerData.data[0].length; ++j) {
    let counter = 0;
    for (let k = worker_threads_1.workerData.id - 1; k < worker_threads_1.workerData.id + 2; ++k) {
        for (let l = j - 1; l < j + 2; ++l) {
            if (k >= 0 &&
                l >= 0 &&
                k < worker_threads_1.workerData.data.length &&
                l < worker_threads_1.workerData.data[0].length &&
                !(k == worker_threads_1.workerData.id && l == j)) {
                if (worker_threads_1.workerData.data[k][l] == 1) {
                    ++counter;
                }
            }
        }
    }
    if (worker_threads_1.workerData.data[worker_threads_1.workerData.id][j] && counter < 2) {
        tmp.push(0);
    }
    else if (worker_threads_1.workerData.data[worker_threads_1.workerData.id][j] && (counter == 2 || counter == 3)) {
        tmp.push(1);
    }
    else if (worker_threads_1.workerData.data[worker_threads_1.workerData.id][j] && counter > 3) {
        tmp.push(0);
    }
    else if (!worker_threads_1.workerData.data[worker_threads_1.workerData.id][j] && counter == 3) {
        tmp.push(1);
    }
    else {
        tmp.push(0);
    }
}
worker_threads_1.parentPort?.postMessage(tmp);
