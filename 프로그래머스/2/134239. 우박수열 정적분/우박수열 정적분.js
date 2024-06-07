function solution(k, ranges) {
    
    
    const getGraph = function(num) {
        const graph = [ num ];
        while (num !== 1) {
            if (num % 2 === 0) {
                num /= 2;
            } else if (num % 2 === 1) {
                num = num * 3 + 1;
            }
            graph.push(num);
        }
        return graph;
    }
    
    const getArea = function(graph) {
        const area = [];
        for (let i = 0; i < graph.length - 1; i++) {
            if (graph[i] < graph[i + 1]) {
                area.push(graph[i] + (graph[i + 1] - graph[i]) / 2);
            } else {
                area.push(graph[i + 1] + (graph[i] - graph[i + 1]) / 2);
            }
        }
        return (area);
    }
    
    const area = getArea(getGraph(k));
    const answer = [];

    for (const range of ranges) {
        const [start, end] = [range[0], area.length + range[1]];
        if (start > end) {
            answer.push(-1);
            continue;
        }
        let sum = 0;
        for (let i = start; i < end; i++)
            sum += area[i];
        answer.push(sum);
    }
    
    

    return answer;
}



// 1 * 5 = 5
// 1 * 11 / 2 = 5.5

// 1 * 8 = 8
// 1 * 8 / 2 = 4

// 1 * 4 = 4
// 1 * 4 / 2 = 2

// 1 * 2 = 2
// 1 * 2 / 2 = 1

// 1 * 1 = 1
// 1 * 1 / 2 = 0.5