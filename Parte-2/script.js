let arregloGlobal = [];

const sleep = (ms) => new Promise(resolve => setTimeout(resolve, ms));

function cargarLabiales() {
    const input = document.getElementById('arrayInput').value;
    arregloGlobal = input.split(',').map(num => parseInt(num.trim())).filter(num => !isNaN(num));
    renderizarLabiales();
}

function renderizarLabiales() {
    const container = document.getElementById('vanity-container');
    container.innerHTML = ''; 

    arregloGlobal.forEach((num, index) => {
        const img = document.createElement('img');
        
        img.src = `Lomuto/v${num}.png`; 
        
        img.className = 'lipstick';
        img.id = `lip-${index}`;
        container.appendChild(img);
    });
}

// --- INICIO DEL ALGORITMO LOMUTO ---
async function particionLomuto(arr, low, high) {
    let pivot = arr[high]; 
    let i = low - 1;

    const imgPivot = document.getElementById(`lip-${high}`);
    if(imgPivot) imgPivot.style.filter = "drop-shadow(0 0 15px red)";

    for (let j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            await intercambiarVisual(arr, i, j);
        }
    }
    
    await intercambiarVisual(arr, i + 1, high);
    
    if(imgPivot) imgPivot.style.filter = "none";
    
    return i + 1;
}

async function quickSortLomuto(arr, low, high) {
    if (low < high) {
        let pi = await particionLomuto(arr, low, high);
        
        await quickSortLomuto(arr, low, pi - 1);
        await quickSortLomuto(arr, pi + 1, high);
    }
}

async function intercambiarVisual(arr, idx1, idx2) {
    if (idx1 === idx2) return; 

    const img1 = document.getElementById(`lip-${idx1}`);
    const img2 = document.getElementById(`lip-${idx2}`);

    if(!img1 || !img2) return;

    img1.classList.add('swapping');
    img2.classList.add('swapping');
    await sleep(400); 

    let temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;

    renderizarLabiales();

    document.getElementById(`lip-${idx1}`).classList.add('swapping');
    document.getElementById(`lip-${idx2}`).classList.add('swapping');
    await sleep(400);
    
    document.getElementById(`lip-${idx1}`).classList.remove('swapping');
    document.getElementById(`lip-${idx2}`).classList.remove('swapping');
    await sleep(200);
}

async function iniciarLomuto() {
    const botones = document.querySelectorAll('button');
    botones.forEach(b => b.disabled = true);

    await quickSortLomuto(arregloGlobal, 0, arregloGlobal.length - 1);

    botones.forEach(b => b.disabled = false);
    document.getElementById('arrayInput').value = arregloGlobal.join(', ');
}

window.onload = cargarLabiales;