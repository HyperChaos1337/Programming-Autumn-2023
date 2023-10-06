import java.util.Arrays;

public class TimSort {

    public static int MIN_RUN = 32;
    public static int gallop_count = 7;

    public static void min_run(int size) {

        assert size >= 0;
        int value = 0;
        while (size >= 64) {
            value |= size & 1;
            size >>= 1;
        }
        MIN_RUN = size + value;

    }

    static void insertionSort(int[] arr, int left, int right) {

        int temp;
        for (int i = left + 1; i < right + 1; i++) {
            int j = i;
            while (j > left && arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }

    }

    public static void merge_sort(int[] arr, int left, int middle, int right) {
        int len1 = middle - left + 1, len2 = right - middle;
        int[] arr1 = new int[len1];
        int[] arr2 = new int[len2];
        int gallop = 0;
        System.arraycopy(arr, left, arr1, 0, len1);
        System.arraycopy(arr, middle + 1, arr2, 0, len2);
        int i = 0, j = 0, k = left;
        while (i < len1 && j < len2) {
            if (gallop == gallop_count) {
                if (arr1[i] <= arr2[j]) {
                    arr[k++] = arr1[i++];
                    if (i < len1) arr[k++] = arr1[i++];
                } else {
                    i -= 2;
                    k -= 2;
                    gallop = 0;
                }
            } else if (arr1[i] <= arr2[j]) {
                arr[k++] = arr1[i++];
                gallop++;
            } else {
                arr[k++] = arr2[j++];
                gallop = 0;
            }
        }
        while (i < len1) {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        while (j < len2) {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }

    public static void timSort(int[] arr) {

        min_run(arr.length);
        for (int start = 0; start < arr.length; start += MIN_RUN) {
            int end = Math.min(start + MIN_RUN - 1, arr.length - 1);
            insertionSort(arr, start, end);
        }

        int size = MIN_RUN, doubleSize;
        while (size < arr.length) {
            doubleSize = 2 * size;
            for (int left = 0; left < arr.length; left += doubleSize) {
                int middle = Math.min(arr.length - 1, left + size - 1);
                int right = Math.min(left + doubleSize - 1, arr.length - 1);
                if (middle < right) merge_sort(arr, left, middle, right);
            }
            size = doubleSize;
        }

    }

    public static void main(String[] args) {

        final int N = 10;
        int[] array = new int[N];
        for(int i = 0; i < array.length; i++) array[i] = (int) (Math.random()*(1000+1));
        System.out.println(Arrays.toString(array));
        timSort(array);
        System.out.println(Arrays.toString(array));

    }

}
