//
//  21_w13_p2.cpp
//  week13Graph
//
//  Created by ���ֹ� on 2023/05/24.
//

/*
 �Ҽ� ��Ʈ��ũ ���� ���� - �׷� ��� ��õ
 (ģ��, ģ���� ģ��, �׷�)

 ����) ������ �����Ƿ� ������ �򰥸��� �ʰ� �����ϸ鼭 �ڵ� ¥��
 */

#include <iostream>
#include <vector>

using namespace std;

int graph[501][501];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int numOfSubscribers, numOfCmd, sizeOfGroup, numberOfUser;
    cin >> numOfSubscribers >> numOfCmd;

    /*
     (�����ڼ�)*(�����ڼ�)��ŭ�� ���߹迭(�׷���)�� ����� ģ�����踦 �Է¹޴´�.
     */
    for (int i = 1; i <= numOfSubscribers; i++) {
        for (int j = 1; j <= numOfSubscribers; j++) {
            cin >> graph[i][j];
        }
    }

    /*
     �׷��� �����ϱ� ������ �����̸� 1, �ƴϸ� 0�� ���
     */
    for (int i = 0; i < numOfCmd; i++) {
        cin >> sizeOfGroup; // �׷� �������� ���� �Է¹޴´�.

        vector<int> group;
        for (int j = 0; j < sizeOfGroup; j++) {
            cin >> numberOfUser; // ���� �ٸ� ������� ��ȣ���� �Է¹ް� ���Ϳ� ����
            group.push_back(numberOfUser);
        }

        int result = 0; // ����� ������ ����
        for (int j = 0; j < group.size(); j++) {
            for (int l = 0; l < group.size(); l++) {
                if (j == l) continue; // �ڽ��� ��� �Ѿ

                result = 0;

                if (graph[group[j]][group[l]] == 1) {
                    // ģ���� ���
                    result = 1;
                }
                else {
                    // ģ���� ģ���� ���
                    for (int o = 1; o <= numOfSubscribers; o++) {
                        if (graph[group[j]][o] == 1 && graph[o][group[l]] == 1) {
                            result = 1;
                            break;
                        }
                    }
                }
                if (result == 0) break; // ģ����, ģ���� ģ���� �ƴ� ��� �׷� ���� �Ұ� -> ��� 0
            }
            if (result == 0) break; // ģ����, ģ���� ģ���� �ƴ� ��� �׷� ���� �Ұ� -> ��� 0
        }
        cout << result << "\n"; // ��� ���
    }
}