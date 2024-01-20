// package sorting-and-order.merge-sort;

public class MergeSort {

	static int[] mergeTwoSorderArray(int[] arr1, int[] arr2) {
		int[] sortedArray = new int[arr1.length + arr2.length];

		int i = 0;
		int j = 0;
		int k = 0;

		while (i < arr1.length && j < arr2.length) {
			if (arr1[i] > arr2[j]) {
				sortedArray[k] = arr2[j];
				j++;
				k++;
			} else {
				sortedArray[k] = arr1[i];
				i++;
				k++;
			}
		}

		if (i == arr1.length) {
			while (j < arr2.length) {
				sortedArray[k] = arr2[j];
				j++;
				k++;
			}
		}

		if (j == arr2.length) {
			while (i < arr1.length) {
				sortedArray[k] = arr1[i];
				i++;
				k++;
			}
		}

		return sortedArray;
	}

	static int[] mergeSort(int[] arr, int low, int high) {
		if (low == high) {
			int[] newArr = new int[1];
			newArr[0] = arr[low];
			return newArr;
		}

		int mid = (low + high) / 2;
		int[] left = mergeSort(arr, low, mid);
		int[] right = mergeSort(arr, mid + 1, high);

		int[] merged = mergeTwoSorderArray(left, right);

		return merged;
	}

	public static void main(String[] args) {
		int[][] test = new int[][] { { 3, 1, 2 }, { 4, 2, 3 }, { 5, 2, 1 } };

		for (int[] e : test) {
			int[] sorted = mergeSort(e, 0, test.length - 1);
			for (int t : sorted) {
				System.out.print(t + " ");
			}
			System.out.println();
		}
	}

}
