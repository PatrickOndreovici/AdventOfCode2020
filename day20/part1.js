const fs = require('fs');
const { checkServerIdentity } = require('tls');

let data = fs.readFileSync('./input.txt', {encoding:'utf8', flag:'r'}); 

data = data.split('\r\n\r\n');

let size = Math.sqrt(data.length);

let tile = {}, id = [];

const Adauga = (matrix, nr) => {
    id.push(nr);
    let top = 0, top2 = 0, bot = 0, bot2 = 0;
    let left = 0, left2 = 0, right = 0, right2 = 0;
    for (let i = 0; i < 10; ++i){
        if (matrix[0][i] === '#'){
            top = top | (1 << i);
        }
        if (matrix[9][i] === '#'){
            bot = bot | (1 << i);
        }
        if (matrix[0][9 - i] === '#'){
            top2 = top2 | (1 << i);
        }
        if (matrix[9][9 - i] === '#'){
            bot2 = bot2 | (1 << i);
        }
        if (matrix[i][0] === '#'){
            left = left | (1 << i);
        }
        if (matrix[9 - i][0] === '#'){
            left2 = left2 | (1 << i);
        }
        if (matrix[i][9] === '#'){
            right = right | (1 << i);
        }
        if (matrix[9 - i][9] === '#'){
            right2 = right2 | (1 << i);
        }
    }
    tile[nr] = [[top, right, bot, left], 
                [right, bot2, left, top2], 
                [bot2, left2, top2, right2], 
                [left2, top, right2, bot],
                [bot, right2, top, left2],
                [left, bot, right, top],
                [top2, left, bot2, right],
                [right2, top2, left2, bot2]
            ];
    
}


for (let i = 0; i < data.length; ++i){
    let matrix = [];
    let aux = data[i].split('\r\n');
    let nr = "";
    for (let j = 0; j < aux[0].length; ++j){
        if (aux[0][j] >= '0' && aux[0][j] <= '9'){
            nr = nr + aux[0][j];
        }
    }
    for (let j = 1; j < aux.length; ++j){
        matrix.push(aux[j]);
    }
    Adauga(matrix, nr);
}

let m = new Array(size + 1);
for (let i = 0; i < size + 1; ++i){
    m[i] = new Array(size + 1);
}
let bagat = new Array(id.length).fill(0);

let ans = 1;

const Back = (row, col) => {
    if (row == size + 1){
        ans = 1;
        ans = ans * Number(m[1][1].id) * Number(m[1][size].id) * Number(m[size][1].id) * Number(m[size][size].id);
        return;
    }
    for (let i = 0; i < id.length; ++i){
        if (bagat[i] === 0){
            for (let j = 0; j < 8; ++j){
                let pot = 0;
                if (row == 1){
                    ++pot;
                }
                else{
                    let sus = m[row - 1][col].id, dirSus = m[row - 1][col].dir;
                    if (tile[id[i]][j][0] === tile[sus][dirSus][2]){
                        ++pot;
                    }
                }
                if (col == 1){
                    ++pot;
                }
                else{
                    let stanga = m[row][col - 1].id, dirStanga = m[row][col - 1].dir;
                    if (tile[id[i]][j][3] === tile[stanga][dirStanga][1]){
                        ++pot;
                    }
                }
                if (pot == 2){
                    bagat[i] = 1;
                    m[row][col] = {id: id[i], dir: j};
                    if (col == size){
                        Back(row + 1, 1);
                    }
                    else{
                        Back(row, col + 1);
                    }
                    bagat[i] = 0;
                }
            }
        }
    }
}

Back(1, 1);

console.log(ans);