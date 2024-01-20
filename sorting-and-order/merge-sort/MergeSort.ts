class MergeSort {
    static mergeTwoSortedArray(arr1: number[], arr2: number[]): number[] {
        const sortedArray: number[] = new Array(arr1.length + arr2.length);

        let i: number = 0;
        let j: number = 0;
        let k: number = 0;

        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] > arr2[j]) {
                sortedArray[k] = arr2[j];
                j++;
            } else {
                sortedArray[k] = arr1[i];
                i++;
            }
            k++;
        }

        while (i < arr1.length) {
            sortedArray[k] = arr1[i];
            i++;
            k++;
        }

        while (j < arr2.length) {
            sortedArray[k] = arr2[j];
            j++;
            k++;
        }

        return sortedArray;
    }

    static mergeSort(arr: number[], low: number, high: number): number[] {
        if (low === high) {
            return [arr[low]];
        }

        const mid: number = Math.floor((low + high) / 2);
        const left: number[] = MergeSort.mergeSort(arr, low, mid);
        const right: number[] = MergeSort.mergeSort(arr, mid + 1, high);

        return MergeSort.mergeTwoSortedArray(left, right);
    }

}

const test: number[] = [66, 31, 13, 22, 19, 99, 198, 15];

const sortedArray: number[] = MergeSort.mergeSort(test, 0, test.length - 1);

console.log(sortedArray.join(' '));
